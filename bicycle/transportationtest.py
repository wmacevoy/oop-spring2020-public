import unittest

from transportation import Transportation
from bicycle import Bicycle
from car import Car
from typing import List,cast

class TransporationTest(unittest.TestCase):

    def testGoCarGo(self):
        car = Car()
        self.assertEqual(car.going,False)
        car.start()
        self.assertEqual(car.going,True)
        car.stop()
        self.assertEqual(car.going,False)

    def testCarsAndBicycles(self):
        movers : List[Transportation] = []
        movers.append(Car(10, 0.5))
        movers.append(Car(15, 0.25))
        movers.append(Bicycle("red"))
        for mover in movers:
            mover.start()
        for i in range(len(movers)):
            self.assertEqual(movers[i].going,True, f"i={i}")

# think of movers[1] as a Car (not just transportation)
        car : Car = cast(Car,movers[1])
        car.fuel = 0.0
        self.assertEqual(movers[1].going, False)

if __name__ == '__main__':
    unittest.main()
