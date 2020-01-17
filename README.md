# SoftwareSerial
A Master/Slave bidirectional serial communication using SoftWareSerial builtin Arduino library.
in order for a master to retrieve data from analog pins A0 to A3 of the slave.

## Master
### Master.ino
Connects to SoftwareSerial on port 10 and 11
<br>
Exposes a method to send command to a slave and waits for response.

## Slave
### Slave.ino
Connects to SoftwareSerial on port 10 and 11
<br>
Listen for commands from a master. Parse the commands and sends the response back to the master.