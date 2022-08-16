package main

type nameAndAge struct {
	Age int
	Name string
}

func (n *nameAndAge) HappyBirthday() {
	n.Age++
}

type Declared nameAndAge
type Alias = nameAndAge

func main() {
	var number int32 = 15
	//var another int64 = number // not ok, underlying type is different
	var another int64 = int64(number) // explisit cast, ok
	var loss int16 = int16(number) // and even such
	loss++
	another++

	var decl Declared = Declared{13, "Ivan"}
	var alias Alias = Alias{17, "Igor"}
	alias.HappyBirthday() // ok, method set saved
	//decl.HappyBirthday() // not ok, method set is null
	decl.Age++
}