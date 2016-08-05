$(document).ready(function(){

	$("#pop-up").click(function() {
		alert("Welcome to my [BLOODY] portfolio!")
	});

	// function moveRight(){
	// 	console.log("im right")
	// 	$(".pic-me").animate({
	// 		right: '+=550px'
	// 	}, 1000, moveLeft);
	function moveLeft(){
		console.log("I'm left")
		$(".pic-me").animate({
			left: '200px',
			width: '300px'
		});
	}

	$(".pic-me").click(function() {
		moveLeft();
	});
 

	$(".arduino").click(function() {
		$("#arduino").attr("src","images/arduino_yes.jpg")
	});
});