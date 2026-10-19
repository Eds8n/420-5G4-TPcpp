#ifndef ACTIVITYLOG_H
#define ACTIVITYLOG_H

#include <string>
using namespace std;

class ActivityLog {
private:
    string filePath;

public:
    ActivityLog(const string& path);
    void log(const string& action, const string& details);
};

#endif