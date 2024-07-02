Action()
{
	lr_start_transaction("UC2_BuyTicket");

	
	lr_start_transaction("home_page");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Not A(Brand\";v=\"99\", \"Google Chrome\";v=\"121\", \"Chromium\";v=\"121\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_custom_request("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Method=GET", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(10);

	web_custom_request("header.html", 
		"URL=http://localhost:1080/WebTours/header.html", 
		"Method=GET", 
		"Resource=0", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t4.inf", 
		"Mode=HTTP", 
		LAST);

	lr_think_time(12);

	web_reg_find("Text=A Session ID has been created and loaded into a cookie called MSO.",
		LAST);
	
	web_custom_request("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t5.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_reg_save_param("userSession",
		"LB=userSession\" value=\"",
		"RB=\"/>",
		LAST);
	
	web_custom_request("nav.pl", 
		"URL=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t7.inf", 
		"Mode=HTTP", 
		LAST);

	
	web_custom_request("home.html", 
		"URL=http://localhost:1080/WebTours/home.html", 
		"Method=GET", 
		"Resource=0", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t8.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("home.html_2", 
		"URL=http://localhost:1080/WebTours/home.html", 
		"Method=GET", 
		"Resource=0", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t20.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);
	
	lr_end_transaction("home_page", LR_AUTO);


	lr_start_transaction("login");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(42);
	
	web_reg_find("Text=User password was correct",
	    LAST);

	web_custom_request("login.pl", 
		"URL=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t9.inf", 
		"Mode=HTTP", 
		"Body=userSession={userSession}&username={login}&password={password}&login.x=47&login.y=9&JSFormSubmit=off", 
		LAST);

	web_concurrent_start(NULL);

	web_reg_find("Text=Web Tours Navigation Bar",
		LAST);

	web_custom_request("nav.pl_2", 
		"URL=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t10.inf", 
		"Mode=HTTP", 
		LAST);

	web_reg_find("Text=Welcome to Web Tours",
		LAST);

	web_custom_request("login.pl_2", 
		"URL=http://localhost:1080/cgi-bin/login.pl?intro=true", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t11.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(43);

	lr_start_transaction("click_flights");
	
	web_reg_find("Text=User has returned to the search page",
		LAST);

	web_custom_request("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t12.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_custom_request("nav.pl_3", 
		"URL=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t13.inf", 
		"Mode=HTTP", 
		LAST);

	web_reg_find("Text=Flight Selections",
		LAST);

	web_custom_request("reservations.pl", 
		"URL=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t14.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("click_flights",LR_AUTO);

	lr_start_transaction("find_flight");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(57);

	web_reg_find("Text/IC= from <B>{depart}</B> to <B>{arrive}</B>",
		LAST);

	
/*Correlation comment - Do not change!  Original value='080;792;04/30/2024' Name ='CorrelationParameter' Type ='RecordReplay'*/
//	web_reg_save_param_attrib(
//		"ParamName=CorrelationParameter",
//		"TagName=input",
//		"Extract=value",
//		"Name=outboundFlight",
//		"Type=radio",
//		LAST);
		
		web_reg_save_param("CorrelationParameter",
		"LB=outboundFlight\" value=\"",
		"RB=\"",
		LAST);

//  outboundFlight" value="080;792;04/30/2024" 

//	web_reg_save_param_regexp(
//		"ParamName=outboundFlight1",
//		"RegExp=outboundFlight\\\" value=\\\"([0-9]{3};)[0-9]{3};[0-9]{2}/[0-9]{2}/[0-9]{4}\\\"",
//		SEARCH_FILTERS,
//		LAST);
//		
//	web_reg_save_param_regexp(
//		"ParamName=outboundFlight2",
//		"RegExp=outboundFlight\\\" value=\\\"[0-9]{3};([0-9]{3};)[0-9]{2}/[0-9]{2}/[0-9]{4}\\\"",
//		SEARCH_FILTERS,
//		LAST);
//
//	web_reg_save_param_regexp(
//		"ParamName=outboundFlight3",
//		"RegExp=outboundFlight\\\" value=\\\"[0-9]{3};[0-9]{3};([0-9]{2}/)[0-9]{2}/[0-9]{4}\\\"",
//		SEARCH_FILTERS,
//		LAST);
//		
//	web_reg_save_param_regexp(
//		"ParamName=outboundFlight4",
//		"RegExp=outboundFlight\\\" value=\\\"[0-9]{3};[0-9]{3};[0-9]{2}/([0-9]{2}/)[0-9]{4}\\\"",
//		SEARCH_FILTERS,
//		LAST);
//
//	web_reg_save_param_regexp(
//		"ParamName=outboundFlight5",
//		"RegExp=outboundFlight\\\" value=\\\"[0-9]{3};[0-9]{3};[0-9]{2}/[0-9]{2}/([0-9]{4})\\\"",
//		SEARCH_FILTERS,
//		LAST);
		
		
	web_reg_find("Text/DIG=From {depart} (#) To {arrive} (#)",
		LAST);

	web_custom_request("reservations.pl_2", 
		"URL=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t15.inf", 
		"Mode=HTTP", 
		"Body=advanceDiscount=0&depart={depart}&departDate={departDate}&arrive={arrive}&returnDate={returnDate}&numPassengers=1&seatPref={seatPref}&seatType={seatType}&findFlights.x=40&findFlights.y=5&.cgifields=roundtrip&.cgifields=seatType&.cgifields=seatPref", 
		LAST);
		
//	lr_save_string("", "outboundFlight");
//	lr_save_string(lr_eval_string("{outboundFlight1}{outboundFlight2}{outboundFlight3}{outboundFlight4}{outboundFlight5}"), "outboundFlight");
	

	web_convert_param("CorrelationParameter_URL2",
		"SourceString={CorrelationParameter}",
		"SourceEncoding=HTML",
		"TargetEncoding=URL",
		LAST);

	lr_end_transaction("find_flight",LR_AUTO);

	lr_think_time(27);

	lr_start_transaction("choose_flight");

	web_custom_request("reservations.pl_3",
		"URL=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t16.inf",
		"Mode=HTTP",
		"Body=outboundFlight={CorrelationParameter_URL2}&numPassengers=1&advanceDiscount=0&seatType={seatType}&seatPref={seatPref}&reserveFlights.x=72&reserveFlights.y=10",
		LAST);

	lr_end_transaction("choose_flight",LR_AUTO);

	lr_think_time(53);

	lr_start_transaction("payment_details");
	
	web_reg_find("Text/IC=from {depart} to {arrive}",
		LAST);

	web_custom_request("reservations.pl_4",
		"URL=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t18.inf",
		"Mode=HTTP",
		"Body=firstName={firstName}&lastName={lastName}&address1={address1}&address2={address2}&pass1={firstName}+{lastName}&creditCard={creditCard}&expDate={expDate}&oldCCOption=&numPassengers=1&seatType={seatType}&seatPref={seatPref}&outboundFlight={CorrelationParameter_URL2}&advanceDiscount=0&returnFlight=&JSFormSubmit=off&buyFlights.x=50&buyFlights.y=9&.cgifields=saveCC",
		LAST);

	lr_end_transaction("payment_details",LR_AUTO);

	lr_start_transaction("logout");

	web_revert_auto_header("Origin");

	lr_think_time(30);

	web_reg_find("Text= A Session ID has been created and loaded into a cookie called MSO.",
		LAST);

	web_custom_request("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t19.inf", 
		"Mode=HTTP", 
		LAST);

	web_reg_find("Text=Web Tours Navigation Bar",
		LAST);

	web_custom_request("nav.pl_4", 
		"URL=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t21.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	lr_end_transaction("UC2_BuyTicket", LR_AUTO);

	
	return 0;
}