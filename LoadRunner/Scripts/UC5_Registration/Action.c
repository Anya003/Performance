Action()
{   lr_start_transaction("UC5_Registration");

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
		"\"Chromium\";v=\"124\", \"Google Chrome\";v=\"124\", \"Not-A.Brand\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");
	
	web_reg_find("Text=Web Tours",
		LAST);

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

	lr_think_time(24);

		web_custom_request("header.html", 
			"URL=http://localhost:1080/WebTours/header.html", 
			"Method=GET", 
			"Resource=0", 
			"Referer=http://localhost:1080/WebTours/", 
			"Snapshot=t2.inf", 
			"Mode=HTTP", 
			LAST);
	
	 web_reg_find("Text=A Session ID has been created and loaded into a cookie called MSO",
		LAST);
	
		web_custom_request("welcome.pl", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/WebTours/", 
			"Snapshot=t3.inf", 
			"Mode=HTTP", 
			LAST);
	
		web_concurrent_start(NULL);
		
		web_reg_find("Text=Web Tours",
		LAST);

		web_custom_request("nav.pl", 
			"URL=http://localhost:1080/cgi-bin/nav.pl?in=home", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
			"Snapshot=t4.inf", 
			"Mode=HTTP", 
			LAST);
	web_reg_find("Text=To make reservations,please enter your account information to the left",
		LAST);

		web_custom_request("home.html", 
			"URL=http://localhost:1080/WebTours/home.html", 
			"Method=GET", 
			"Resource=0", 
			"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
			"Snapshot=t5.inf", 
			"Mode=HTTP", 
			LAST);

	web_concurrent_end(NULL);
    
	lr_end_transaction("home_page", LR_AUTO);

	lr_start_transaction("sign_up_now");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(168);

	web_reg_find("Text=User Information",
		LAST);

		web_custom_request("login.pl", 
			"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/WebTours/home.html", 
			"Snapshot=t6.inf", 
			"Mode=HTTP", 
			LAST);
	
		web_custom_request("profileValidate.js", 
			"URL=http://localhost:1080/WebTours/profileValidate.js", 
			"Method=GET", 
			"Resource=1", 
			"RecContentType=application/javascript", 
			"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
			"Snapshot=t7.inf", 
			LAST);

	lr_end_transaction("sign_up_now",LR_AUTO);

	lr_start_transaction("fill_user_data");

		web_add_header("Origin", 
			"http://localhost:1080");
	
		lr_think_time(2030);
	
		web_reg_find("Text=Thank you, <b>{login}</b>, for registering ",
		LAST);

		
		web_custom_request("login.pl_2", 
			"URL=http://localhost:1080/cgi-bin/login.pl", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
			"Snapshot=t8.inf", 
			"Mode=HTTP", 
			"Body=username={login}&password={password}&passwordConfirm={password}&firstName={firstName}&lastName={lastName}&address1={address1}&address2={address2}&register.x=47&register.y=11", 
			LAST);

	lr_end_transaction("fill_user_data",LR_AUTO);

	lr_think_time(26);

	lr_start_transaction("click_continue");

		web_custom_request("button_next.gif", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/login.pl", 
			"Snapshot=t9.inf", 
			"Mode=HTTP", 
			LAST);
	
		web_concurrent_start(NULL);
	
		web_reg_find("Text=Web Tours Navigation Bar",
		LAST);

		web_custom_request("nav.pl_2", 
			"URL=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
			"Snapshot=t10.inf", 
			"Mode=HTTP", 
			LAST);
	
		web_reg_find("Text=Welcome to Web Tours",
		LAST);

		web_custom_request("login.pl_3", 
			"URL=http://localhost:1080/cgi-bin/login.pl?intro=true", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
			"Snapshot=t11.inf", 
			"Mode=HTTP", 
			LAST);
	
		web_concurrent_end(NULL);

	lr_end_transaction("click_continue",LR_AUTO);

	lr_think_time(67);

	lr_start_transaction("sign_out");

	web_reg_find("Text=A Session ID has been created and loaded into a cookie called MSO",
		LAST);
	
		web_custom_request("SignOff Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t12.inf", 
			"Mode=HTTP", 
			LAST);
	
		web_concurrent_start(NULL);
	
		web_custom_request("nav.pl_3", 
			"URL=http://localhost:1080/cgi-bin/nav.pl?in=home", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
			"Snapshot=t13.inf", 
			"Mode=HTTP", 
			LAST);
	
		web_custom_request("home.html_2", 
			"URL=http://localhost:1080/WebTours/home.html", 
			"Method=GET", 
			"Resource=0", 
			"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
			"Snapshot=t14.inf", 
			"Mode=HTTP", 
			LAST);
	
		web_concurrent_end(NULL);

	lr_end_transaction("sign_out",LR_AUTO);
    
	lr_end_transaction("UC5_Registration", LR_AUTO);

	return 0;
}