/*__      _____  ___ _ __  
 *\ \ /\ / / _ \/ _ \ '_ \ 
 * \ V  V /  __/  __/ | | |
 *  \_/\_/ \___|\___|_| |_|
 * Command Line App
 * Version 0.4.0
 */
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_LEN 80
#define API_URL "https://api.ween.io"

typedef struct {
  char *message;
  char *v;
} ween_data;

void get_ween(ween_data * w);

int main(int argc, char *argv[])
{
  char messageTitle[MAX_LEN];
  char messageBody[MAX_LEN];
  char messagePassphrase[MAX_LEN];
  char messageDeleteAfterFirstView[MAX_LEN];

  ween_data title;
  title.message = "What is the title of your message? ";
  title.v = messageTitle;
  get_ween(&title);

  ween_data body;
  body.message = "What is your message? ";
  body.v = messageBody;
  get_ween(&body);

  ween_data passphrase;
  passphrase.message = "What is the passphrase? ";
  passphrase.v = messagePassphrase;
  get_ween(&passphrase);

  ween_data deleteafter;
  deleteafter.message = "Delete after first view (1 yes | 0 no)? ";
  deleteafter.v = messageDeleteAfterFirstView;
  get_ween(&deleteafter);

  char postdata[2048];

  if(strlen(messagePassphrase) > 0) {
    sprintf(postdata, "messageTitle=%s&messageBody=%s&messagePassphrase=%s&messageDeleteAfterFirstView=%s", messageTitle, messageBody, messagePassphrase, messageDeleteAfterFirstView);
  } else {
    sprintf(postdata, "messageTitle=%s&messageBody=%s&messageDeleteAfterFirstView=%s", messageTitle, messageBody, messageDeleteAfterFirstView);
  }

  CURL *curl;
  CURLcode res;

  /*sprintf(postdata, "messageTitle=%s&messageBody=%s&messagePassphrase=%s&messageDeleteAfterFirstView=%s", argv[1], argv[2], argv[3], argv[4]);*/
  /*printf("%s\n", postdata);*/

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, API_URL);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);

    /* if we don't provide POSTFIELDSIZE, libcurl will strlen() by
       itself */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postdata));

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

void get_ween(ween_data * w) {
  printf("%s", w->message);
  fgets(w->v, MAX_LEN, stdin);
  if ((strlen(w->v)>0) && (w->v[strlen (w->v) - 1] == '\n')) {
    w->v[strlen (w->v) - 1] = '\0';
  }
}