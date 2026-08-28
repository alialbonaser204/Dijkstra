#include <iostream>
#include <string>
#include "source/include/Graph.hpp"
#include "source/include/Station.hpp"
#include "source/include/CarStep.hpp"
#include "source/include/TrainStep.hpp"
#include "source/include/PlaneStep.hpp"
#include "source/include/PairHash.hpp"

// Functie om een station te kiezen
Station* chooseStation(const std::vector<Station*>& stations, const std::string& prompt) {
    int keuze = -1;
    while (keuze < 0 || keuze >= stations.size()) {
        std::cout << prompt << std::endl;
        for (int i = 0; i < stations.size(); ++i) {
            std::cout << i << ": " << stations[i]->getName() << std::endl;
        }
        std::cin >> keuze;
        if (keuze < 0 || keuze >= stations.size()) {
            std::cout << "Ongeldige keuze, probeer het opnieuw." << std::endl;
        }
    }
    return stations[keuze];
}

int main() {
    // Maak stations aan
    Station* stationA = new Station("Station A");
    Station* stationB = new Station("Station B");
    Station* stationC = new Station("Station C");
    Station* stationD = new Station("Station D");
    Station* stationE = new Station("Station E");
    Station* stationF = new Station("Station F");

    // Maak stappen aan
    Step* carStep1 = new CarStep(stationA, stationB, 4);
    Step* carStep2 = new CarStep(stationA, stationC, 3);
    Step* carStep3 = new CarStep(stationC, stationA, 3);
    Step* carStep4 = new CarStep(stationC, stationB, 5);
    Step* carStep5 = new CarStep(stationC, stationD, 3);
    Step* carStep6 = new CarStep(stationC, stationE, 2);
    Step* carStep7 = new CarStep(stationB, stationA, 4);
    Step* carStep8 = new CarStep(stationB, stationC, 5);
    Step* carStep9 = new CarStep(stationB, stationD, 2);
    Step* carStep10 = new CarStep(stationE, stationC, 2);
    Step* carStep11 = new CarStep(stationE, stationD, 2);
    Step* carStep12 = new CarStep(stationE, stationF, 3);
    Step* carStep13 = new CarStep(stationD, stationB, 2);
    Step* carStep14 = new CarStep(stationD, stationC, 3);
    Step* carStep15 = new CarStep(stationD, stationE, 2);
    Step* carStep16 = new CarStep(stationD, stationF, 1);

    Step* trainStep1 = new TrainStep(stationA, stationD, 21);
    Step* trainStep2 = new TrainStep(stationD, stationF, 0.5);

    Step* planeStep1 = new PlaneStep(stationA, stationC, 0.1);
    Step* planeStep2 = new PlaneStep(stationF, stationA, 0.5);

    stationA->addStep(planeStep1);
    stationF->addStep(planeStep2);
    stationA->addStep(trainStep1);
    stationD->addStep(trainStep2);

    // Voeg stappen toe aan stations
    stationA->addStep(carStep1);
    stationA->addStep(carStep2);
    stationC->addStep(carStep3);
    stationC->addStep(carStep4);
    stationC->addStep(carStep5);
    stationC->addStep(carStep6);
    stationB->addStep(carStep7);
    stationB->addStep(carStep8);
    stationB->addStep(carStep9);
    stationE->addStep(carStep10);
    stationE->addStep(carStep11);
    stationE->addStep(carStep12);
    stationD->addStep(carStep13);
    stationD->addStep(carStep14);
    stationD->addStep(carStep15);
    stationD->addStep(carStep16);

    // Maak een graph aan
    std::vector<Station*> stations = {stationA, stationB, stationC, stationD, stationE, stationF};
    std::vector<Step*> steps = {
            planeStep1, planeStep2,
            trainStep1, trainStep2,
            carStep1, carStep2, carStep3, carStep4, carStep5,
            carStep6, carStep7, carStep8, carStep9, carStep10,
            carStep11, carStep12, carStep13, carStep14, carStep15,
            carStep16
    };
    Graph graph(stations, steps);

    // Maak een map voor de stappen
    std::unordered_map<std::pair<Station*, Station*>, Step*, PairHash> step_map;
    for (auto step : steps) {
        step_map[{step->getFrom(), step->getTo()}] = step;
    }

    // Laat de gebruiker een start- en eindstation kiezen
    Station* startStation = chooseStation(stations, "Kies een startstation:");
    Station* endStation = chooseStation(stations, "Kies een eindstation:");

    // Test Dijkstra's algoritme vanaf het gekozen startstation
    auto result = graph.dijkstra(startStation);
    std::unordered_map<Station*, float> afstanden = result.first;
    std::unordered_map<Station*, Step*> voorgangers = result.second;

    // Print de kortste route naar het gekozen eindstation
    std::cout << "\nKortste route naar " << endStation->getName() << ":" << std::endl;
    graph.printPath(startStation, endStation, voorgangers);
    std::cout << std::endl;

    // Opschonen van dynamisch geheugen
    delete carStep1;
    delete carStep2;
    delete carStep3;
    delete carStep4;
    delete carStep5;
    delete carStep6;
    delete carStep7;
    delete carStep8;
    delete carStep9;
    delete carStep10;
    delete carStep11;
    delete carStep12;
    delete carStep13;
    delete carStep14;
    delete carStep15;
    delete carStep16;

    delete planeStep1;
    delete planeStep2;

    delete trainStep1;
    delete trainStep2;

    delete stationA;
    delete stationB;
    delete stationC;
    delete stationD;
    delete stationE;
    delete stationF;

    return 0;
}
