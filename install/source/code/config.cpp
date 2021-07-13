#include "../lib/config.hpp"
#include <iostream>

TiXmlDocument* loadFile(string filename) {
	TiXmlDocument* file = new TiXmlDocument(filename.c_str());

	if(file -> LoadFile())
		return file;

	return NULL;
}

Config::Config(string filename) {
    TiXmlDocument* xml = loadFile(filename);

    if (xml == NULL) {
        cout << "NÃO CARREGOU" << endl;
        this -> status = true;
    }
    else {
        TiXmlElement* config = xml -> FirstChildElement();

        TiXmlElement* host = config -> FirstChildElement("Host");
        TiXmlElement* appliance = config -> FirstChildElement("Appliance");
        TiXmlElement* images = config -> FirstChildElement("Images");

        if (host == NULL) {
            cout << "HOST ERRO" << endl;
            this -> status = true;
        }
        else {
            this -> hostInterface = host -> Attribute("interface");
            this -> hostIP = host -> Attribute("ip");
            this -> hostNetmask = host -> Attribute("netmask");
        }
        
        if (appliance == NULL) {
            cout << "APP ERRO" << endl;
            this -> status = true;
        }
        else {
            this -> appIP = appliance -> Attribute("ip");
            this -> appNetmask = appliance -> Attribute("netmask");

            TiXmlElement* dhcp = appliance -> FirstChildElement("DHCP");

            if (dhcp == NULL) {
                cout << "DHCP ERRO" << endl;
                this -> status = true;
            }
            else {
                this -> appDhcpRangeStart = dhcp -> Attribute("start");
                this -> appDhcpRangeEnd = dhcp -> Attribute("end");
            }
        }
        
        if (images == NULL) {
            cout << "IMAGES ERRO" << endl;
            this -> status = true;
        }
        else {
            this -> bootImage = images -> Attribute("boot");
            this -> sysUpgradeImage = images -> Attribute("sysupgrade");
        }
    }
}

bool Config::getStatus() {
    return this -> status;
}

ConfigHost Config::getHost() {
    ConfigHost host;

    host.interface = this -> hostInterface;
    host.ip = this -> hostIP;
    host.netmask = this -> hostNetmask;

    return host;
}

ConfigAppliance Config::getAppliance() {
    ConfigAppliance appliance;

    appliance.ip = this -> appIP;
    appliance.netmask = this -> appNetmask;
    appliance.dhcpStart = this -> appDhcpRangeStart;
    appliance.dhcpEnd = this -> appDhcpRangeEnd;

    return appliance;
}

string Config::getBoot() {
    return this -> bootImage;
}

string Config::getUpgrade() {
    return this -> sysUpgradeImage;
}