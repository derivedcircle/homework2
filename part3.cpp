#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;



void ATC(int aircraft_id,int &trafficPattern, bool &ATCSleeping) 
{
    while (true) {
        mtx.lock();
        if (ATCSleeping)
            ATCSleeping = false;
        cout << "Aircraft " << aircraft_id << " requesting landing" << endl;
        if (trafficPattern < 3) {
            
            trafficPattern++;
            
            mtx.unlock();
            /*
            this_thread::sleep_for(chrono::seconds(1)); 
            
            The various potential delays from part 6 used for testing
            */
            mtx.lock();

            cout << "Aircraft " << aircraft_id << " cleared for landing" << endl;
            this_thread::sleep_for(chrono::seconds(1)); // Landing process
            
            cout << "Runway is now free" << endl;
            trafficPattern--;
            if (trafficPattern == 0)
                ATCSleeping = true;
            mtx.unlock();
            break;
        }
        else {
            cout << "Traffic pattern is full. Aircraft " << aircraft_id << " needs to divert to another airport." << endl;
            mtx.unlock();
            break;
        }
    }
}

void part3() {
    int trafficPattern = 0; // Number of aircraft in the traffic pattern
    bool ATCSleeping = true; // Initial state of ATC

    thread aircrafts[10];
    for (int i = 0; i < 10; ++i) {
        aircrafts[i] = thread(ATC, i + 1,ref(trafficPattern), ref(ATCSleeping));
    }

    for (int i = 0; i < 10; ++i) {
        aircrafts[i].join();
    }
        
    

    
    
}
