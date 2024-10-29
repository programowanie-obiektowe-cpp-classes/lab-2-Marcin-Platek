#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
// Konstruktor domyślny - alokacja zasobów w pamięcie
ResourceManager()
{
    resource_wsk = new Resource();
}

// Destruktor - zwalnianie zasobu z pamięci
~ResourceManager()
{
    delete resource_wsk;
}

// Konstruktor kopiujący
ResourceManager(const ResourceManager& other)
{
    resource_wsk = new Resource(*other.resource_wsk);
}

// Operator przypisania kopiującego
ResourceManager& operator=(const ResourceManager& other)
{
    if (this != &other) {
        delete resource_wsk; // Zwolnienie istniejącego zasobu
        resource_wsk = new Resource(*other.resource_wsk); // Kopiowanie zasobu
    }
    return *this;
}

// Funkcja dostępu do zasobu bezpośrednio z pola tablicy `tab`
double getResourceValue() const
{
    return (*resource_wsk).tab[Resource::get_index];
}

double get()
{
    return (*resource_wsk).get();
}

private:
Resource* resource_wsk; // Surowy wskaźnik do zasobu

};
