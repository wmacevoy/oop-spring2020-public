from transportation import Transportation
from typing import Sequence,Set,List,Tuple,Dict
from wheel import Wheel
from transportation import Transportation

class Bicycle(Transportation):
    def __init__(self, color : str, diameter : float = Wheel.DEFAULT_DIAMETER):
        super(Bicycle,self).__init__(started = False)
        self._wheels : List[Wheel] = [Wheel(diameter),Wheel(diameter)]
        self._color : str = color

    @property
    def front(self) -> Wheel:
        return self._wheels[0]

    @property
    def rear(self) -> Wheel:
        return self._wheels[1]

    @property
    def flat(self) -> bool:
        return self.front.flat or self.rear.flat

# override
    @property
    def going(self):
        return  self.started and not self.flat
