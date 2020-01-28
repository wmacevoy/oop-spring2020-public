from typing import Sequence
from wheel import Wheel

class Bicycle:
    def __init__(self, color : str, diameter : float = Wheel.DEFAULT_DIAMETER):
        self._wheels : Sequence[Wheel] = (Wheel(diameter),Wheel(diameter))
        self._color : str = color
        self._started : bool = False

    @property
    def front(self) -> Wheel:
        return self._wheels[0]

    @property
    def rear(self) -> Wheel:
        return self._wheels[1]

    @property
    def flat(self) -> bool:
        return self.front.flat or self.rear.flat

    def start(self) -> None:
        self._started = True

    def stop(self) -> None:
        self._started = False

    @property
    def started(self):
        return self._started

    @property
    def going(self):
        return  self.started and not self.flat
