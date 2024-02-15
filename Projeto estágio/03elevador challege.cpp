#include <iostream>
#include <queue>

using namespace std;

class Elevator {
private:
    int currentFloor;
    queue<int> requests;

public:
    Elevator() : currentFloor(1) {}

    void requestFloor(int floor) {
        requests.push(floor);
    }

    void processRequests() {
        while (!requests.empty()) {
            int nextFloor = requests.front();
            cout << "Moving elevator from floor " << currentFloor << " to floor " << nextFloor << endl;
            currentFloor = nextFloor;
            requests.pop();
        }
    }

    int getCurrentFloor() const {
        return currentFloor;
    }
};

int main() {
    Elevator elevator;

    // Exemplo de solicitações de andares
    elevator.requestFloor(3);
    elevator.requestFloor(2);
    elevator.requestFloor(4);

    // Processa as solicitações e move o elevador
    elevator.processRequests();

    return 0;
    
}
