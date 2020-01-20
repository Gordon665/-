#include <iostream>
#include "mysql++.h"
using namespace std;

int main()
{
    const char* db = "database1";
    const char* server = "127.0.0.1";
    const char* user = "Gordon";
    const char* password = "cbn77534";
    mysqlpp::Connection conn(false);
    if (conn.connect(db, server, user, password))
    {
        cout << "connect succeed." << endl;
        mysqlpp::Query query = conn.query("SELECT * FROM database1.memberdata");
        if (mysqlpp::StoreQueryResult res = query.store())
        {
            cout.setf(ios::left);
            cout << setw(21) << "ID" <<
                    setw(21) << "Account" <<
                    setw(21) << "Password" <<
                    setw(21) << "Name" <<
                    setw(21) << "Phone" <<
                    endl;
            mysqlpp::StoreQueryResult::const_iterator it;
            for (it = res.begin(); it != res.end(); ++it)
            {
                mysqlpp::Row row = *it;
                cout << setw(20) << row[0] << ' ' <<
                        setw(20) << row[1] << ' ' <<
                        setw(20) << row[2] << ' ' <<
                        setw(20) << row[3] << ' ' <<
                        setw(20) << row[4] << ' ' <<
                        endl;
            }
        }
    }
    else
    {
        cout << "connect fail." << endl;
    }
    return 0;
}
