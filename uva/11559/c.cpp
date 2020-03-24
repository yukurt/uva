#include <iostream>
#include <vector>
#include <limits>

struct Hotel
{
    int price = 0;
    std::vector<int> numBeds;
};

class MinCostCalculator
{
public:
    MinCostCalculator();
    void extractInputs(int num_participants);
    void printInputs();
    void printMinCost();
private:
    void reset();
    void extractHotelInfo();
    void calculate();
    bool anyWeekAvailable(Hotel const& hotel);
    int computeHotelCost(Hotel const& hotel);
    bool isHotelSuitable(Hotel const& hotel);

    int numParticipants;
    int budget;
    int numHotels;
    int numWeeks;

    std::vector<Hotel> hotels;

    bool hotelFound;
    int minCost;
};

MinCostCalculator::MinCostCalculator()
{
    reset();
}

void MinCostCalculator::reset()
{
    numParticipants = 0;
    budget = 0;
    numHotels = 0;
    numWeeks = 0;

    hotels.clear();

    hotelFound = false;
    minCost = std::numeric_limits<int>::max();
}

void MinCostCalculator::extractInputs(int num_participants)
{
    reset();

    numParticipants = num_participants;

    std::cin >> budget;
    std::cin >> numHotels;
    std::cin >> numWeeks;

    for (int i = 0; i < numHotels; ++i)
    {
        extractHotelInfo();
    }

    calculate();
}

void MinCostCalculator::extractHotelInfo()
{
    Hotel hotel;

    std::cin >> hotel.price;

    for (int i = 0; i < numWeeks; ++i)
    {
        int num_beds;
        std::cin >> num_beds;
        hotel.numBeds.push_back(num_beds);
    }

    hotels.push_back(hotel);
}

void MinCostCalculator::printInputs()
{
    std::cout << "Input details:\n";

    std::cout << "\tnumParticipants: " << numParticipants << "\n";
    std::cout << "\tbudget: " << budget << "\n";
    std::cout << "\tnumHotels: " << numHotels << "\n";
    std::cout << "\tnumWeeks: " << numWeeks << "\n";

    std::cout << "\tHotels:\n";
    int i = 1;
    for (auto const& hotel: hotels)
    {
        std::cout << "\t\tHotel " << i << ":\n";
        std::cout << "\t\t\tprice: " << hotel.price << "\n";
        std::cout << "\t\t\tnumBeds: ";

        for (auto num_beds: hotel.numBeds)
        {
            std::cout << num_beds << " ";
        }
        std::cout << "\n";
    }
}

bool MinCostCalculator::anyWeekAvailable(Hotel const& hotel)
{
    for (auto num_beds: hotel.numBeds)
    {
        if (numParticipants <= num_beds)
        {
            return true;
        }
    }

    return false;
}

int MinCostCalculator::computeHotelCost(Hotel const& hotel)
{
    return numParticipants * hotel.price;
}

bool MinCostCalculator::isHotelSuitable(Hotel const& hotel)
{
    int cost = computeHotelCost(hotel);
    if (cost > budget)
    {
        return false;
    }

    if (!anyWeekAvailable(hotel))
    {
        return false;
    }

    return true;
}

void MinCostCalculator::calculate()
{
    for (auto const& hotel: hotels)
    {
        if (!isHotelSuitable(hotel))
        {
            continue;
        }

        hotelFound = true;

        int cost = computeHotelCost(hotel);
        if (cost < minCost)
        {
            minCost = cost;
        }
    }
}

void MinCostCalculator::printMinCost()
{
    if (hotelFound)
    {
        std::cout << minCost << "\n";
    }
    else
    {
        std::cout << "stay home\n";
    }
}

int main()
{
    MinCostCalculator calculator;

    for (int num_participants = 0;std::cin >> num_participants;)
    {
        calculator.extractInputs(num_participants);
        //calculator.printInputs();
        calculator.printMinCost();
    }

    return 0;
}
