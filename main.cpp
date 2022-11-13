#include <iostream>
#include <fstream>
#include <thread>
#include <string>

using namespace std;

void Ping(string ip);

pthread_mutex_t mutex;
string packt;


int main(int argc, char *argv[]){
    packt = argv[2];
    pthread_mutex_init(&mutex, NULL);
    ifstream ip(argv[1]);
    string line;
    int countline=0;
    while (getline(ip, line))
    {
        countline++;
    }
    ip.close();
    thread threads[countline];
    ifstream ip1("ips.txt");
    string line1;
    string ips[countline];
    int aux=0;
    cout<<"IP"<<"\t\t"<<"Trans."<<"\t"<<"Rec"<<"\t"<<"Perd."<<"\t"<<"Estado"<<endl;
    cout<<"=============================================="<<endl;
    while (getline(ip1, line1)){
        threads[aux] = thread(Ping, ips[aux]);
        aux++;
    }
    for (int i = 0; i < countline; i++)
    {
        threads[i].join();
    }
    ip.close();
    return 0;
}

    void Ping(string ip)
{
    char buffer[128];
    string result = " ";
    FILE * sistem = popen(("ping " + ip + " -c " + packt).c_str(), "r");
    if (!sistem) {
        cout<< "popen failed!";
    }
    while (!feof(sistem)) {
    if (fgets(buffer, 128, sistem) != NULL)
        result += buffer;
    }
    int i = 0;
    string pack = "";
    while(i<result.length()){
        if (result[i] == ','){
            int j = i+2;
            while(result[j]!= ' '){
                pack += result[j];
                j++;
            }
        }
        i++;
    }
    int packag = stoi(pack);
    int packe = stoi (packt);
    int packr = packe - packag;
    string status;
	if(packe > 0){
        status = "UP";
    }
	else{
        status = "DOWN";
    }
    pthread_mutex_lock(&mutex);
	cout << ip << "\t\t" << packe << "\t" << packag << "\t" << packr << "\t" << status << endl;
    pthread_mutex_unlock(&mutex);

}


