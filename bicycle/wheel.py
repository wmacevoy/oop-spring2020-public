class Wheel:
    BURST_PRESSURE : float = 100.0   # pounds per square inch
    DEFAULT_DIAMETER : float = 29.0  # inches
    DEFAULT_PRESSURE : float = 0.0   # pounds per square inch

    def __init__(self, diameter : float = DEFAULT_DIAMETER, pressure : float = DEFAULT_PRESSURE):
        self._diameter = diameter
        self._pressure = pressure
        self._burst : bool = False
        
    @property
    def diameter(self) -> float:
        return self._diameter
    
    @property
    def pressure(self) -> float:
        return self._pressure

    @pressure.setter
    def pressure(self,value : float) -> None:
        if value < 0:
            raise ValueError(f"pressure {value} must be non-negative")
        if value >= self.BURST_PRESSURE:
            self._burst = True
        if self._burst:
            value = 0.0
        self._pressure = value

    @property
    def flat(self) -> bool:
        return self._pressure == 0.0

    @property
    def burst(self) -> bool:
        return self._burst
