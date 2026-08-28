#include "include/PlaneStep.hpp"

// Constructor voor het initialiseren van een vliegtuig stap met een startstation, eindstation en gewicht
PlaneStep::PlaneStep(Station* from, Station* to, float weight)
        : Step(from, to, weight) {}

// Methode om het type vervoer te verkrijgen (in dit geval 'Plane')
std::string PlaneStep::getTransportType() const {
    return "Plane";
}