var express = require('express');
var app = express();
var bodyParser = require('body-parser');
var urlencodedParser = bodyParser.urlencoded({ extended: true });
var MongoClient = require('mongodb').MongoClient;
app.use(express.static(__dirname + "/../public"));
app.get('/thereget', function (req, res) {
res.sendFile( __dirname + "/" + "19bit0212_project_contact.html" );})
app.post('/therepost',urlencodedParser, function (req, res) {
response = { Name:req.body.cname, Phone:req.body.cpn, Email:req.body.cem, Feedbacksuggestion:req.body.sf};
MongoClient.connect('mongodb://localhost:27017/', function(err, db)
{ if (err) throw err;
console.log("Connected to Database");
var dbo=db.db("mydbcontactus");
dbo.collection('contactus').insert(response, function(err, result)
{ if (err) throw err;
console.log("1 document inserted in your mongodb database" ); });});
console.log(response);
res.end(JSON.stringify(response));})
var server = app.listen(8080, function () {
var host = server.address().address
var port = server.address().port
console.log("listening at http://%s:%s//thereget", host,
port)}) 
