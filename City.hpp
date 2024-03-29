#pragma once
#include "Color.hpp"
#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace pandemic {

    enum City {
            Chicago,
            Miami,
            LosAngeles,
            SanFrancisco, 
            Atlanta,
            MexicoCity, 
            Bogota,
            Lima, 
            Santiago,
            BuenosAires, 
            SaoPaulo,
            Lagos,
            Kinshasa, 
            Johannesburg, 
            Khartoum,
            Cairo,
            Algiers,
            Riyadh,
            Baghdad, 
            Istanbul,
            Paris, 
            Madrid, 
            Karachi,
            Mumbai, 
            Chennai, 
            Moscow,
            StPetersburg,
            Essen, London, 
            Milan,
            Tehran,
            Delhi, 
            Jakarta,
            HoChiMinhCity,
            Manila, 
            Taipei, 
            Osaka,
            Sydney, 
            Shanghai, 
            Beijing, 
            Seoul, 
            Tokyo, 
            Kolkata, 
            Montreal, 
            NewYork,
            Washington, 
            Bangkok, 
            HongKong
    };

        const std::map<City, Color> city_color{
            {Algiers, Black},
            {Atlanta, Blue},
            {Baghdad, Black},
            {Bangkok, Red},
            {Beijing, Red},
            {Bogota, Yellow},
            {BuenosAires, Yellow},
            {Cairo, Black},
            {Chennai, Black},
            {Chicago, Blue},
            {Delhi, Black},
            {Essen, Blue},
            {HoChiMinhCity, Red},
            {HongKong, Red},
            {Istanbul, Black},
            {Jakarta, Red},
            {Johannesburg, Yellow},
            {Karachi, Black},
            {Khartoum, Yellow},
            {Kinshasa, Yellow},
            {Kolkata, Black},
            {Lagos, Yellow},
            {Lima, Yellow},
            {London, Blue},
            {LosAngeles, Blue},
            {Madrid, Blue},
            {Manila, Red},
            {MexicoCity, Yellow},
            {Miami, Yellow},
            {Milan, Blue},
            {Montreal, Blue},
            {Moscow, Black},
            {Mumbai, Black},
            {NewYork, Blue},
            {Osaka, Red},
            {Paris, Blue},
            {Riyadh, Black},
            {SanFrancisco, Blue},
            {Santiago, Yellow},
            {SaoPaulo, Yellow},
            {Seoul, Red},
            {Shanghai, Red},
            {StPetersburg, Blue},
            {Sydney, Red},
            {Taipei, Red},
            {Tehran, Black},
            {Tokyo, Red},
            {Washington, Blue},
        };
    
}