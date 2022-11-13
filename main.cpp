#include <iostream>
#include <fstream>
#include <thread>

using namespace std;

void Ping(string ip);

pthread_mutex_t mutex;

struct IP{
    string ip;
    int Packege;
    int Ploss;
};

int main(int argc, char *argv[]){
    pthread_mutex_init(&mutex, NULL);
    ifstream ip(argv[1]);
    string line;
    int countline=0;
    while (getline(ip, line))
    {
        countline++;
    }
    ip.close();
    struct IP data[countline];
    thread threads[countline];
    ifstream ip1("ips.txt");
    string line1;
    int aux=0;
    cout<<"Id"<<"\t\t"<<"Trans."<<"\t"<<"Rec"<<"\t"<<"Perd."<<"\t"<<"Estado"<<endl;
    cout<<"========================================"<<endl;
    while (getline(ip1, line1)){
        data[aux].Ip = line1;
        data[aux].Packege = atoi(argv[2]);
        threads[aux] = thread(Ping, &data[aux]);
        aux++;
    }
    for (int i = 0; i < lineText; i++)
    {
        threads[i].join();
    }
    ip.close();
    return 0;
}

    void Ping(struct IPINFO *data)
{
    char buffer[128];
    char result = " ";
    FILE * sistem;
    sistem = popen(("ping " + (data)->Ip + " -c " + to_string((data)->Packege) + " | grep -i received").c_str() , "r");
    if (!sistem) {
    return "popen failed!";
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
                packetr += result[j];
                j++;
            }
        }
        i++;
    }

    coustring status;
	if(stoi(receive) > 0){
        status = "UP";
    }
	else{
        status = "DOWN";
    }
	int lost = stoi(pckg) - stoi(receive);
    myMutex.lock();
	if(ip.length() < 10)
	cout << ip << "\t\t" << pckg << "\t" << receive << "\t" << lost << "\t" << status << endl;
	else
	cout << ip << "\t" << pckg << "\t" << receive << "\t" << lost << "\t" << status << endl;
	myMutex.unlock();

}


