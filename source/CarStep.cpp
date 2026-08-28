#include "include/CarStep.hpp"

// Constructor voor het initialiseren van een auto stap met een startstation, eindstation en gewicht
CarStep::CarStep(Station* from, Station* to, float weight)
        : Step(from, to, weight) {}

// Methode om het type vervoer te verkrijgen (in dit geval 'Car')
std::string CarStep::getTransportType() const {
    return "Car";
}