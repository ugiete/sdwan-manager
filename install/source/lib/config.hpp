#if ! defined CONFIG_HPP
#define CONFIG_HPP

#include "tinystr.h"
#include "tinyxml.h"
#include <string>

using namespace std;

typedef struct configHost ConfigHost;
typedef struct configApp ConfigAppliance;

struct configHost {
    string interface;
    string ip;
    string netmask;
};

struct configApp {
    string ip;
    string netmask;
    string dhcpStart;
    string dhcpEnd;
};

class Config {
    private:
        // Host computer variables
        string hostInterface;
        string hostIP;
        string hostNetmask;

        // Appliance variables
        string appIP;
        string appNetmask;
        string appDhcpRangeStart;
        string appDhcpRangeEnd;

        // Images paths
        string bootImage;
        string sysUpgradeImage;

        // ---
        bool status = false;
    public:
        Config(string filename);
        bool getStatus();
        ConfigHost getHost();
        ConfigAppliance getAppliance();
        string getBoot();
        string getUpgrade();
};

#endif