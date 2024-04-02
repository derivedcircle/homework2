#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
// includes all needed header files and sets default namespace as standard for convenience
mutex mtx;



void ATC(int aircraft_id,int &trafficPattern, bool &ATCSleeping) 
{ // this function is designed to be multithreaded
    while (true) {
        mtx.lock(); // lock here for waking up atc and using the ostream to request landing
        if (ATCSleeping)
            ATCSleeping = false;
        cout << "Aircraft " << aircraft_id << " requesting landing" << endl;
        if (trafficPattern < 3) {
            // lock from earlier persists to allow aircraft to enter trafic pattern and incriments counter for that if able
            trafficPattern++;
            
            mtx.unlock();
            /*
            this_thread::sleep_for(chrono::seconds(1)); 
            
            The various potential delays from part 6 used for testing
            */
            mtx.lock(); // locking here for simulated landing sequence

            cout << "Aircraft " << aircraft_id << " cleared for landing" << endl;
            this_thread::sleep_for(chrono::seconds(1)); // Landing process
            
            cout << "Runway is now free" << endl;
            trafficPattern--;
            if (trafficPattern == 0) // if nobody is in pattern, the atc goes to sleep
                ATCSleeping = true;
            mtx.unlock();
            break; // the thread controling this aircraft is now done
        }
        else { // if there are more then 3 aircraft in the patern, the plane is forced to divert
            cout << "Traffic pattern is full. Aircraft " << aircraft_id << " needs to divert to another airport." << endl;
            mtx.unlock(); // first lock (from the start of the function) persists to here for ostream protecion
            break; // aircraft is no longer here and the thread controling the aircraft is now done
        }
    }
}

void part3() {
    int trafficPattern = 0; // Number of aircraft in the traffic pattern
    bool ATCSleeping = true; // Initial state of ATC

    thread aircrafts[10]; // creates 10 aircraft threads
    for (int i = 0; i < 10; ++i) {
        aircrafts[i] = thread(ATC, i + 1,ref(trafficPattern), ref(ATCSleeping));
    } // assigns the atc task for all aircraft

    for (int i = 0; i < 10; ++i) {
        aircrafts[i].join(); // gets all tasks to join to run throuh simulation for all 10 aircraft
    }
        
    

    
    
}
