var path = "/foo/bar/value";
var value = 1000;

setprop(path, value);
if (getprop(path) != value) 
 die("setprop/getprop not working properly!");
else
 print("Success: setprop/getprop support works!");

var listeners_work = 0;
var listener_test = "/test/listener/value";
setlistener(listener_test, func {
	print("SUCCESS: listeners work"); 
	listeners_work=1;
	} 
);

setprop(listener_test, 1);
if (!listeners_work) die("Listeners are broken now!");

var timers_work = 0;
var timer_test = "/test/systime";
settimer( func setprop(timer_test,1), 0);
if (!timer_test) die ("Nasal timers are broken now!");

