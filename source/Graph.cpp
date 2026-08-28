#include "include/Graph.hpp"
#include <iostream>
#include <limits>

// Constructor die de graaf initialiseert met een gegeven lijst van stations en stappen.
Graph::Graph(const std::vector<Station*>& stations, const std::vector<Step*>& steps)
        : stations(stations), steps(steps) {}

// Methode om alle stations in de graaf te verkrijgen.
std::vector<Station*> Graph::getStations() const {
    return stations;
}

// Methode om alle stappen in de graaf te verkrijgen.
std::vector<Step*> Graph::getSteps() const {
    return steps;
}

// Methode die het Dijkstra-algoritme uitvoert om de kortste paden vanaf een startstation te berekenen.
// Retourneert een paar van:
// - Een map van stations naar de kortste afstand vanaf het startstation.
// - Een map van stations naar de voorgaande stappen op het kortste pad.
std::pair<std::unordered_map<Station*, float>, std::unordered_map<Station*, Step*>> Graph::dijkstra(Station* bron) {
    std::unordered_map<Station*, float> afstanden; // Map die de kortste afstand naar elk station bijhoudt.
    std::unordered_map<Station*, Step*> voorgangers; // Map die de voorgaande stap op het kortste pad naar elk station bijhoudt.

    // Initialiseer de afstanden naar alle stations als oneindig en de voorgangers als null.
    for (Station* station : stations) {
        afstanden[station] = std::numeric_limits<float>::infinity();
        voorgangers[station] = nullptr;
    }

    // Zet de afstand naar het startstation op 0.
    afstanden[bron] = 0;

    // Lambda-functie om stations te vergelijken op basis van hun afstanden.
    auto vergelijker = [&afstanden](Station* lhs, Station* rhs) {
        return afstanden[lhs] > afstanden[rhs];
    };

    // Priority queue om de stations te verwerken, gesorteerd op afstand.
    std::priority_queue<Station*, std::vector<Station*>, decltype(vergelijker)> wachtrij(vergelijker);
    wachtrij.push(bron);

    // Verwerk de wachtrij totdat deze leeg is.
    while (!wachtrij.empty()) {
        Station* huidig = wachtrij.top();
        wachtrij.pop();

        // Doorloop alle stappen vanaf het huidige station.
        for (Step* stap : huidig->getSteps()) {
            Station* buur = stap->getTo();
            float nieuweAfstand = afstanden[huidig] + stap->getWeight();

            // Als een kortere afstand naar het buurstation is gevonden, werk de afstanden en voorgangers bij.
            if (nieuweAfstand < afstanden[buur]) {
                afstanden[buur] = nieuweAfstand;
                voorgangers[buur] = stap;
                wachtrij.push(buur);
            }
        }
    }

    // Retourneer de afstanden en voorgangers.
    return {afstanden, voorgangers};
}

// Hulpmethode om het pad te printen van een startstation naar een eindstation.
// Gebruikt een map van voorgaande stappen om het pad te reconstrueren.
void Graph::printPathHelper(Station* start, Station* end, const std::unordered_map<Station*, Step*>& voorgangers) const {
    if (start == end) {
        std::cout << start->getName();
    } else if (voorgangers.at(end) == nullptr) {
        std::cout << "No path from " << start->getName() << " to " << end->getName() << std::endl;
    } else {
        printPathHelper(start, voorgangers.at(end)->getFrom(), voorgangers);
        auto step = voorgangers.at(end);
        std::cout << " -> (" << step->getTransportType() << ") -> " << end->getName();
    }
}

// Methode om het volledige pad te printen van een startstation naar een eindstation.
// Gebruikt de printPathHelper methode om het pad te reconstrueren en te printen.
void Graph::printPath(Station* start, Station* end, const std::unordered_map<Station*, Step*>& voorgangers) const {
    if (start == end) {
        std::cout << start->getName();
    } else if (voorgangers.find(end) == voorgangers.end() || voorgangers.at(end) == nullptr) {
        std::cout << "No path from " << start->getName() << " to " << end->getName() << std::endl;
    } else {
        printPathHelper(start, end, voorgangers);
        std::cout << std::endl;
    }
}
