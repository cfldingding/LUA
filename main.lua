--[[print("hello world");
--test for the lua 
local  lua_getData()
{
	return dd;
}
print("bad world","ccc")
function dang()
	local i = 0
	local a = {
		["hello"] = 100,
		[3] = true
	}
	print(a.hello)
end

function lua_add(a,b)
	return a+b,a-b
end

print(lua_add(2,1))

for i = 0,9,2 do
	print(i)
end

for i = 9,0,-1 do
	print(i)
end

a = {
	["x"] = 1,
	[100] = true,

	[1] = "hello,world",
	[2] = "qihao",
}

for k,v in pairs(a) do
	print(k,v)
end

for k,v in ipairs(a) do
	print(k,v)
end
--]]
local class = {}
function class.foo(a,b)
	return a+b
end
return class