#include <iostream>
#include <curl/curl.h>
#include "json/json.h"

using namespace std;

int get_ip_info(string);

string response;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    int res = get_ip_info("");
	cout << response;
    return 0;
}

int get_ip_info(string ip_addr) {
	CURL *curl;
	CURLcode res;
	string url = "https://freegeoip.app/json/"  + ip_addr;

	curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return res;
}