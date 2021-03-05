package greetings

import (
    "errors"
    "fmt"
    "math/rand"
    "time"
)

// Hello returns a greeting for the named person.
// Function declaration --> strong typed inputs,
// Multiple outputs possible with the ()
func Hello(name string) (string, error) {
    // If no name was given, return an error with a message.
    if name == "" {
        // New() function from errors makes a new error message
        return "", errors.New("empty name")
    }


    // Return a greeting that embeds the name in a message.
    // Go uses := for assignment when declaring and initializing
    // variables on one line.
    message := fmt.Sprintf(randomFormat(), name)
    // nil is like None in Python --> in this case there is no error
    return message, nil
}

// Hellos returns a map that associates each of the named people
// with a greeting message.
// A map looks like the various Map<> types implemented by Java
// Has keys, values with strong types for each
func Hellos(names []string) (map[string]string, error) {
    // A map to associate names with messages.
    // the make() function is used for initialization
    // kind of like new in Java
    messages := make(map[string]string)
    // Loop through the received slice of names, calling
    // the Hello function to get a message for each name.
    // the range object in Go is a lot like enumerate() in Python
    // the _ is the blank identifier, which just ignores the first out
    // of names (the current index)
    for _, name := range names {
        message, err := Hello(name)
        if err != nil {
            return nil, err
        }
        // In the map, associate the retrieved message with 
        // the name.
        messages[name] = message
    }
    return messages, nil
}

// init sets initial values for variables used in the function.
// just re-seeding based on current time --> commonly done
func init() {
    rand.Seed(time.Now().UnixNano())
}

// randomFormat returns one of a set of greeting messages. The returned
// message is selected at random.
func randomFormat() string {
    // A slice of message formats.
    // Slices are very powerful in Go
    // They are dynamically sized arrays, resizing as content added/removed
    // %v means "default format" for variable based on its type
    formats := []string{
        "Hi, %v. Welcome!",
        "Great to see you, %v!",
        "Hail, %v! Well met!",
    }

    // Return a randomly selected message format by specifying
    // a random index for the slice of formats.
    // slices have len() like python lists
    // rand package has Intn() like java nextInt()
    return formats[rand.Intn(len(formats))]
}
