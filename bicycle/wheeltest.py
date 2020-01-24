import unittest

from wheel import Wheel


class WheelTest(unittest.TestCase):

    def testDefaults(self):
        wheel = Wheel()
        self.assertEqual(wheel.pressure, Wheel.DEFAULT_PRESSURE)
        self.assertEqual(wheel.diameter, Wheel.DEFAULT_DIAMETER)
        self.assertEqual(wheel.burst, False)
        self.assertEqual(wheel.flat, Wheel.DEFAULT_PRESSURE == 0.0)

    def testSpecific(self):
        testDiameter : float = 22.0
        testPressure : float = Wheel.BURST_PRESSURE/2.0
        wheel = Wheel(diameter = testDiameter, pressure = testPressure)
        self.assertEqual(wheel.pressure, testPressure)
        self.assertEqual(wheel.diameter, testDiameter)
        self.assertEqual(wheel.burst,False)
        self.assertEqual(wheel.flat,False)

    def testFlat(self):
        testPressure = Wheel.BURST_PRESSURE / 2.0
        wheel = Wheel()
        wheel.pressure = testPressure
        self.assertEqual(wheel.pressure, testPressure)
        self.assertEqual(wheel.flat, False)
        wheel.pressure = 0.0
        self.assertEqual(wheel.flat, True)
    
    def testBurst(self):
        wheel = Wheel()
        wheel.pressure = Wheel.BURST_PRESSURE / 2.0
        self.assertEqual(wheel.flat,False)
        self.assertEqual(wheel.burst,False)
        wheel.pressure = Wheel.BURST_PRESSURE
        self.assertEqual(wheel.pressure,0.0)
        self.assertEqual(wheel.flat,True)
        self.assertEqual(wheel.burst,True)
        wheel.pressure = Wheel.BURST_PRESSURE / 2.0
        self.assertEqual(wheel.pressure,0.0)
        self.assertEqual(wheel.flat,True)
        self.assertEqual(wheel.burst,True)

if __name__ == '__main__':
    unittest.main()
