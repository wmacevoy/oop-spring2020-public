from transportation import Transportation
from typing import Sequence,Set,List,Tuple,Dict
from wheel import Wheel
from transportation import Transportation

class Car(Transportation):
    DEFAULT_FUEL : float = 1.0
    FRONT_LEFT : int = 0
    FRONT_RIGHT : int = 1
    REAR_LEFT : int = 2
    REAR_RIGHT : int = 3
    def __init__(self, diameter : float = Wheel.DEFAULT_DIAMETER, fuel : float = DEFAULT_FUEL):
        super(Car,self).__init__(started = False)
        self._wheels : List[Wheel] = [Wheel(diameter) for i in range(4)]
        self._fuel = fuel

    @property
    def fuel(self) -> float:
        return self._fuel

    @fuel.setter
    def fuel(self,value : float) -> None:
        if value < 0 or value > 1:
            raise ValueError("invalid fuel amount")
        self._fuel = value

    @property
    def frontLeft(self) -> Wheel:
        return self._wheels[self.FRONT_LEFT]

    @property
    def rearLeft(self) -> Wheel:
        return self._wheels[self.REAR_LEFT]
    @property
    def frontRight(self) -> Wheel:
        return self._wheels[self.FRONT_RIGHT]

    @property
    def rearRight(self) -> Wheel:
        return self._wheels[self.REAR_RIGHT]
    @property
    def flat(self) -> bool:
        ans : bool = False
        for wheel in self._wheels:
            ans = ans or wheel.flat
        return ans

# override
    @property
    def going(self):
        return  self.started and not self.flat and self._fuel > 0.0
