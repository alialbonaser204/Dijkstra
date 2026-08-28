#include "include/TrainStep.hpp"


// Constructor voor het initialiseren van een trein stap met een startstation, eindstation en gewicht
TrainStep::TrainStep(Station* from, Station* to, float weight)
        : Step(from, to, weight) {}

// Methode om het type vervoer te verkrijgen (in dit geval 'Train')
std::string TrainStep::getTransportType() const {
    return "Train";
}
