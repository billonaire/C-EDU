while (true)
{
	char* command = readCommand();
	handleCommand(command);

}

while (true)
{
	Event* event = waitForEvent();
	dispatchEvent(event);
}

while (true)
{
	processInput();
	update();
	render();
}


double previous = getCurrnetTime();
double lag = 0.0;
while (true)
{
	double current = getCurrentTime();
	double elapsed = current - previous;
	previous = current;
	lag += elapsed;
	processInput();
	
	while (lag >= MS_PER_UPDATE)
	{
		update();
		lag -= MS_PER_UPDATE;
	}
	render(lag / MS_PER_UPDATE);
}
 