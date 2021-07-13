#include "lib/config.hpp"
#include "lib/functions.hpp"
#include <regex>
#include <iostream>

using namespace std;

string confdir(string argv0);
vector<string> tokenize(string input, const char* delim);

int main(int argc, char* argv[]) {
    if (argc == 2) {
        string confFile = confdir(argv[0]);
        Config* conf = new Config(confFile);

        if (conf -> getStatus())
            cout << "DEU ERRO!" << endl;
        else
            cout << "TUDO CERTO!" << endl;
        
        if (strcmp(argv[1], "--ip") == 0)
            setIP(
                conf -> getHost().interface,
                conf -> getHost().ip + "/" + conf -> getHost().netmask
            );
        else
            cout << "Comando inválido" << endl;
    }
    else
        cout << "Comando inválido" << endl;

    return 0;
}

string confdir(string argv0) {
    string confpath = "";

    if (argv0[0] == '.') {
        string path = argv0;
        path.erase(0, 1);

        vector<string> tokens = tokenize(path, "/");

        FILE* fp = popen("pwd", "r");
        char pwd[256];

        fgets(pwd, sizeof(pwd), fp);
        pclose(fp);

        confpath += pwd;
        confpath.pop_back();

        for (auto &&token : tokens) {
            confpath += "/";
            confpath += token;
        }

        confpath += "/config.xml";

        return confpath;
    }

    if (argv0[0] == '/') {
        vector<string> tokens = tokenize(argv0, "/");

        for (auto &&token : tokens) {
            confpath += "/";
            confpath += token;
        }

        confpath += "/config.xml";
        
        return confpath;
    }

    string cmd = "which ";
    cmd += argv0;

    FILE* fp = popen(cmd.c_str(), "r");
    char path[256];

    fgets(path, sizeof(path), fp);
    pclose(fp);

    confpath += path;
    confpath.pop_back();

    return confpath;
}

vector<string> tokenize(string input, const char* delim) {
    char* token = strtok(const_cast<char*>(input.c_str()), delim);
    vector<string> tokens;

    while (token != nullptr) {
        tokens.push_back(string(token));
        token = strtok(nullptr, delim);
    }

    tokens.pop_back();
    
    return tokens;
}