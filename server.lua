socket = require('socket')
port=3030
server=socket.bind('*',port)
io.write("Listening to port"..port.."\n")
sv=server:accept()
io.write("connection established\n")
while true do
	msg=sv:receive()
	io.write(msg .. "\n")
	io.write("Respond>")
	sv:send(io.read() .. "\n")
end
io.read()
