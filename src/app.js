Pebble.addEventListener('ready', function(e) {
	console.log('Ready!');
}, function (error) {
	console.log('Error subscribing to topic: ' + error);
});

Pebble.addEventListener('appmessage', function(e) {
  console.log('Received message: ' + JSON.stringify(e.payload));

  if (e.payload.action) {
	  
	  switch (e.payload.action) {
		  case 1:
			  console.log("Channel turned up");
			  break;
			  
		  case 2:
			  console.log("Channel turned down");
			  break;

		  case 3:
			  console.log("Volume turned up");
			  break;

		  case 4:
			  console.log("Volume turned down");
			  break;
	  }
		
	
  }
});
