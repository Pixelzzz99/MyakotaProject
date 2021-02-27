#include "Subword.hpp"

Subword::Subword(Strategy *interface) : interface(interface)
{
}

Subword::~Subword()
{
    delete this->interface;
}

std::string Subword::DoAlgorithm()
{
    return interface->solve();
}

void Subword::setInterface(Strategy *interface)
{
    delete this->interface;
    this->interface = interface;
}

std::string Subword::get_first_word() const
{
    return interface->get_first_word();
}

std::string Subword::get_second_word() const
{
    return interface->get_second_word();
}
