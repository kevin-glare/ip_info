#include <iostream>
#include <curl/curl.h>
#include "json/json.h"

using namespace std;

void get_ip_info(string);
void parsing_json(string);

string response;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(int argc, char *argv[]) {
	string ip;

	if (argc > 1)
		ip = argv[1];

    get_ip_info(ip);
	parsing_json(response);
	cout << response;
    return 0;
}

void get_ip_info(string ip_addr) {
	CURL     *curl;
	CURLcode res;
	string   url = "https://freegeoip.app/json/"  + ip_addr;

	curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}

void parsing_json(string response) {}