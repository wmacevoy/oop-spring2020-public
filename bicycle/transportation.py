class Transportation:
    def __init__(self, started : bool = False):
        self._started : bool = started
    @property
    def started(self) -> bool:
        return self._started

    def start(self) -> None:
        self._started = True

    def stop(self) -> None:
        self._started = False

    @property
    def going(self) -> bool:
        return self._started
