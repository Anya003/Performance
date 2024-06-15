Action2()
{

	lr_start_transaction("itinerary");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"124\", \"Google Chrome\";v=\"124\", \"Not-A.Brand\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(27);

	web_custom_request("welcome.pl_2", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t38.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_custom_request("nav.pl_3", 
		"URL=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t39.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("itinerary.pl", 
		"URL=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t40.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("itinerary",LR_AUTO);

	lr_start_transaction("delete_ticket");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(33);

	web_custom_request("itinerary.pl_2", 
		"URL=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t41.inf", 
		"Mode=HTTP", 
		"Body=1=on&flightID=365334086-795-JB&flightID=128002603-1560-JB&flightID=128002992-2368-JB&flightID=128002992-3137-JB&flightID=128002992-3907-JB&flightID=128002992-4676-JB&flightID=128002992-5445-JB&flightID=128002992-6214-JB&flightID=128002992-6984-JB&flightID=1280166709-77012-JB&flightID=1280029684-84729-JB&flightID=128017-9-JB&flightID=128016-10-JB&flightID=128016-10-JB&flightID=128001-11-JB&flightID=128001-12-JB&flightID=128001-13-JB&flightID=128001-13-JB&flightID=128002-14-JB&flightID="
		"128001-15-JB&flightID=128002-16-JB&flightID=128001-16-JB&flightID=128002-17-JB&flightID=128001-18-JB&flightID=128001-19-JB&flightID=128017-20-JB&flightID=128002-20-JB&flightID=128001-21-JB&flightID=128001-22-JB&flightID=128016-23-JB&flightID=128001-23-JB&flightID=128002-24-JB&flightID=128002-25-JB&flightID=128017-26-JB&flightID=128001-26-JB&flightID=128017-27-JB&flightID=128001-28-JB&flightID=128002-29-JB&flightID=128001-30-JB&flightID=128017-30-JB&flightID=128002-31-JB&flightID=128017-32-JB&"
		"flightID=128001-33-JB&removeFlights.x=52&removeFlights.y=8&.cgifields=33&.cgifields=32&.cgifields=21&.cgifields=7&.cgifields=26&.cgifields=17&.cgifields=2&.cgifields=1&.cgifields=18&.cgifields=30&.cgifields=16&.cgifields=27&.cgifields=25&.cgifields=28&.cgifields=40&.cgifields=20&.cgifields=14&.cgifields=24&.cgifields=10&.cgifields=31&.cgifields=35&.cgifields=11&.cgifields=42&.cgifields=22&.cgifields=13&.cgifields=23&.cgifields=29&.cgifields=6&.cgifields=39&.cgifields=36&.cgifields=3&.cgifields=9&"
		".cgifields=41&.cgifields=12&.cgifields=15&.cgifields=38&.cgifields=8&.cgifields=4&.cgifields=34&.cgifields=37&.cgifields=43&.cgifields=19&.cgifields=5", 
		LAST);

	lr_end_transaction("delete_ticket",LR_AUTO);

	return 0;
}