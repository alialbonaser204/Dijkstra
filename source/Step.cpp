#include "include/Step.hpp"

// Constructor voor het initialiseren van een stap met een startstation, eindstation en gewicht
Step::Step(Station* from, Station* to, float weight)
        : from(from), to(to), weight(weight) {}

// Methode om het startstation van de stap te verkrijgen
Station* Step::getFrom() {
    return from;
}

// Methode om het eindstation van de stap te verkrijgen
Station* Step::getTo() {
    return to;
}

// Methode om het gewicht van de stap te verkrijgen
float Step::getWeight() {
    return weight;
}
