/*__      _____  ___ _ __  
 *\ \ /\ / / _ \/ _ \ '_ \ 
 * \ V  V /  __/  __/ | | |
 *  \_/\_/ \___|\___|_| |_|
 * Command Line App
 * Version 0.2.0
 */
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_LEN 80

int main(int argc, char *argv[])
{
  char messageTitle[MAX_LEN];
  char messageBody[MAX_LEN];
  char messagePassphrase[MAX_LEN];
  char messageDeleteAfterFirstView[MAX_LEN];

  char postdata[2048];

  printf("What is the title of your message? ");
  /* Get the input, with size limit. */
  fgets(messageTitle, MAX_LEN, stdin);
   /* Remove trailing newline, if there. */
  if ((strlen(messageTitle)>0) && (messageTitle[strlen (messageTitle) - 1] == '\n')) {
    messageTitle[strlen (messageTitle) - 1] = '\0';
  }

  printf("What is your message? ");
  /* Get the input, with size limit. */
  fgets(messageBody, MAX_LEN, stdin);
   /* Remove trailing newline, if there. */
  if ((strlen(messageBody)>0) && (messageBody[strlen (messageBody) - 1] == '\n')) {
    messageBody[strlen (messageBody) - 1] = '\0';
  }

  printf("What is the passphrase? ");
  /* Get the input, with size limit. */
  fgets(messagePassphrase, MAX_LEN, stdin);
   /* Remove trailing newline, if there. */
  if ((strlen(messagePassphrase)>0) && (messagePassphrase[strlen (messagePassphrase) - 1] == '\n')) {
    messagePassphrase[strlen (messagePassphrase) - 1] = '\0';
  }

  printf("Delete after first view (1 yes | 0 no)? ");
  /* Get the input, with size limit. */
  fgets(messageDeleteAfterFirstView, MAX_LEN, stdin);
   /* Remove trailing newline, if there. */
  if ((strlen(messageDeleteAfterFirstView)>0) && (messageDeleteAfterFirstView[strlen (messageDeleteAfterFirstView) - 1] == '\n')) {
    messageDeleteAfterFirstView[strlen (messageDeleteAfterFirstView) - 1] = '\0';
  }

  sprintf(postdata, "messageTitle=%s&messageBody=%s&messagePassphrase=%s&messageDeleteAfterFirstView=%s", messageTitle, messageBody, messagePassphrase, messageDeleteAfterFirstView);

  CURL *curl;
  CURLcode res;

  /*sprintf(postdata, "messageTitle=%s&messageBody=%s&messagePassphrase=%s&messageDeleteAfterFirstView=%s", argv[1], argv[2], argv[3], argv[4]);*/
  /*printf("%s\n", postdata);*/

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.ween.io");
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
