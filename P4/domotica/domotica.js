var http = require("http");
var url = require("url");
var fs = require("fs");
var path = require("path");
var socketio = require("socket.io");
var MongoClient = require('mongodb').MongoClient;
var MongoServer = require('mongodb').Server;
var mimeTypes = { "html": "text/html", "jpeg": "image/jpeg", "jpg": "image/jpeg", "png": "image/png", "js": "text/javascript", "css": "text/css", "swf": "application/x-shockwave-flash"};

var httpServer = http.createServer(
	function(request, response) {
		var uri = url.parse(request.url).pathname;
		if (uri=="/") uri = "/domotica.html";
		var fname = path.join(process.cwd(), uri);
		fs.exists(fname, function(exists) {
			if (exists) {
				fs.readFile(fname, function(err, data){
					if (!err) {
						var extension = path.extname(fname).split(".")[1];
						var mimeType = mimeTypes[extension];
						response.writeHead(200, mimeType);
						response.write(data);
						response.end();
					}
					else {
						response.writeHead(200, {"Content-Type": "text/plain"});
						response.write('Error de lectura en el fichero: '+uri);
						response.end();
					}
				});
			}
			else{
				console.log("Peticion invalida: "+uri);
				response.writeHead(200, {"Content-Type": "text/plain"});
				response.write('404 Not Found\n');
				response.end();
			}
		});
	}
);


httpServer.listen(8080);
var io = socketio(httpServer);

MongoClient.connect("mongodb://localhost:27017/domotica", { useUnifiedTopology: true }, function(err, db) {
	


	var dbo = db.db("domotica");

	dbo.createCollection("eventos", function(err, collection){
		if(!err){
			console.log("Colección creada con éxito");
		}
	});

	io.sockets.on('connection',function(socket) {

		socket.on('nuevos-datos', function (datos) {
			var fecha_actual = new Date();
			dbo.collection("eventos").insertOne({valor_temperatura:datos[0], valor_luminosidad:datos[1], fecha:fecha_actual}, {safe:true}, function(err, result) {
				if(!err){
					console.log("Nuevos valores introducidos con exito");
				}
				
			}); 
			io.sockets.emit('emision-medidas', datos);
		});

		socket.on('estado-aire', function(data) {
			console.log(data[0]);
			io.sockets.emit('all-connections', data);
		});

		socket.on('alerta', function(msg){
			console.log(msg);
			io.sockets.emit('emision-alerta', msg);
		});
		
		socket.on('estado-persianas', function(data) {
			console.log(data[0]);
			io.sockets.emit('all-connections', data);
		});	
	});
});

	




console.log("Simulación domótica inicializada");


