from transportation import Transportation
import unittest

from car import Car
from typing import List,cast

class CarTest(unittest.TestCase):

    def testDefaults(self):
        car = Car()
        self.assertEqual(car.fuel,Car.DEFAULT_FUEL)
        self.assertEqual(car.started,False)


    def testCarFuel(self):
        car : Car = Car()
        self.assertEqual(car.fuel,Car.DEFAULT_FUEL)
        car.fuel = 0.0
        self.assertEqual(car._fuel,0.0)
        car.fuel = 0.5
        self.assertEqual(car._fuel,0.5)

    def testCarTransportationFuel(self):
        transportation : Transportation = Car()
        car : Car = cast(Car,transportation)        
        car.fuel = 0.0
        self.assertEqual(car._fuel,0.0)
        self.assertEqual(transportation.going, False)
        self.assertEqual(car.going, False)

if __name__ == '__main__':
    unittest.main()
