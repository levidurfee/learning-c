#include <my_global.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
}

int main()
{
    int i;
    MYSQL *con = mysql_init(NULL);

    if(con == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        return 1;
    }

    if(mysql_real_connect(con, "localhost", "weenc", "weenc", "weenc", 0, NULL, 0) == NULL) {
        finish_with_error(con);
        return 1;
    }

    if(mysql_query(con, "SELECT name FROM people")) {
        finish_with_error(con);
        return 1;
    }

    MYSQL_RES *result = mysql_store_result(con);

    if(result == NULL) {
        finish_with_error(con);
        return 1;
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    while((row = mysql_fetch_row(result))) {
        for(i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_close(con);

    return 0;
}
