Action1()
{

	lr_start_transaction("delete_ticket");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_header("sec-ch-ua", 
		"\"Chromium\";v=\"124\", \"Google Chrome\";v=\"124\", \"Not-A.Brand\";v=\"99\"");

	web_add_header("sec-ch-ua-mobile", 
		"?0");

	web_add_header("sec-ch-ua-platform", 
		"\"Windows\"");

	lr_think_time(51);

	web_custom_request("itinerary.pl_2", 
		"URL=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t29.inf", 
		"Mode=HTTP", 
		"Body=1=on&flightID=2514622275-7802-JB&flightID=365334086-1564-JB&flightID=128002603-2330-JB&flightID=128002992-3137-JB&flightID=128002992-3907-JB&flightID=128002992-4676-JB&flightID=128002992-5445-JB&flightID=128002992-6214-JB&flightID=128002992-6984-JB&flightID=128002992-7753-JB&flightID=1280166709-84705-JB&flightID=1280029684-92421-JB&flightID=128017-100-JB&flightID=128016-107-JB&flightID=128016-115-JB&flightID=128001-123-JB&flightID=128001-130-JB&flightID=128001-138-JB&flightID=128001-146-JB&"
		"flightID=128002-153-JB&flightID=128001-161-JB&flightID=128002-169-JB&flightID=128001-176-JB&flightID=128002-184-JB&flightID=128001-192-JB&flightID=128001-200-JB&flightID=128017-207-JB&flightID=128002-215-JB&flightID=128001-223-JB&flightID=128001-230-JB&flightID=128016-238-JB&flightID=128001-246-JB&flightID=128002-253-JB&flightID=128002-261-JB&flightID=128017-269-JB&flightID=128001-276-JB&flightID=128017-284-JB&flightID=128001-292-JB&flightID=128002-300-JB&flightID=128001-307-JB&flightID="
		"128017-315-JB&flightID=128002-323-JB&flightID=128017-330-JB&flightID=128001-338-JB&removeFlights.x=33&removeFlights.y=8&.cgifields=33&.cgifields=32&.cgifields=21&.cgifields=7&.cgifields=26&.cgifields=17&.cgifields=2&.cgifields=1&.cgifields=18&.cgifields=30&.cgifields=16&.cgifields=44&.cgifields=27&.cgifields=25&.cgifields=28&.cgifields=40&.cgifields=20&.cgifields=14&.cgifields=24&.cgifields=10&.cgifields=31&.cgifields=35&.cgifields=11&.cgifields=42&.cgifields=22&.cgifields=13&.cgifields=23&"
		".cgifields=29&.cgifields=6&.cgifields=39&.cgifields=36&.cgifields=3&.cgifields=9&.cgifields=41&.cgifields=12&.cgifields=15&.cgifields=38&.cgifields=8&.cgifields=4&.cgifields=34&.cgifields=37&.cgifields=43&.cgifields=19&.cgifields=5", 
		LAST);

	lr_end_transaction("delete_ticket",LR_AUTO);

	return 0;
}