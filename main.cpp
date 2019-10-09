#include <iostream>
#include <curl/curl.h>

using namespace std;

void get_ip_info(string);

int main(int argc, char *argv[]) {
    get_ip_info("");
    return 0;
}

void get_ip_info(string ip_addr) {
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
    string url = "http://whatismyip.akamai.com/";

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		res = curl_easy_perform(curl);
        cout << res << endl;
		curl_easy_cleanup(curl);
    }
}