/*__      _____  ___ _ __  
 *\ \ /\ / / _ \/ _ \ '_ \ 
 * \ V  V /  __/  __/ | | |
 *  \_/\_/ \___|\___|_| |_|
 * Command Line App
 * Version 0.1.0
 */
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char *argv[])
{
  CURL *curl;
  CURLcode res;

  static const char *postthis="messageTitle=hello&messageBody=hello&messagePassphrase=test&messageDeleteAfterFirstView=1";

  char postdata[2048];
  sprintf(postdata, "messageTitle=%s&messageBody=%s&messagePassphrase=%s&messageDeleteAfterFirstView=%s", argv[1], argv[2], argv[3], argv[4]);
  printf("%s", postdata);

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.ween.io");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);

    /* if we don't provide POSTFIELDSIZE, libcurl will strlen() by
       itself */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  printf("\r\n");
  return 0;
}
