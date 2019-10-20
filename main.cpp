#include <iostream>
#include <regex>
#include <curl/curl.h>

using namespace std;

void get_ip_info(string ip_addr);
void show_result();

const string sorry = "Sorry, something went wrong...";
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

	if (response.empty()) {
		cout << sorry << endl;
	} else {
		show_result();

	}

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

void show_result() {
	response.insert(1, "\n\t");
	response.insert(response.length()-2, "\n");
	response = regex_replace(response, regex(R"(\,)"), ",\n\t");
	response = regex_replace(response, regex(R"(\:)"), ": ");
	cout << response << endl;
}