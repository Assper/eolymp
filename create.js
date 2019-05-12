const fs = require('fs')
const command = process.argv[2]

const mainTemplate = `#include <fstream>

using namespace std;

int main() {
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    

    inf.close();
    outf.close();
    return 0;
}
`

const testTemplate = `#include <iostream>
#include <assert.h>

using namespace std;

int main() {
    cout << "All tests are done!" << endl;
    return 0;
}
`

try {
    if (!command) { throw 'Command not found!' }

    const name = command.trim()
    if (!name) { throw 'Command can not be empty!' }

    const path = `${__dirname}/${name}`
    if (fs.existsSync(path)) { throw 'Directory already exist!' }

    fs.mkdirSync(path)

    const out = new Promise(resolve => resolver(resolve, {path, name: 'out', type: 'Directory'}))
    const main = new Promise(resolve => resolver(resolve, {path, name: 'main.cpp', type: 'File', template: mainTemplate}))
    const test = new Promise(resolve => resolver(resolve, {path, name: 'test.cpp', type: 'File', template: testTemplate}))
    const input = new Promise(resolve => resolver(resolve, {path, name: 'input.txt'}))
    const output = new Promise(resolve => resolver(resolve, {path, name: 'output.txt'}))

    Promise.all([out, main, test, input, output]).then(() => console.log(`Task ${name} created in folder: ${path}`))
} catch (e) {
    console.error(e)
}

function resolver(resolve, params) {
    const {
        path,
        name,
        type = 'File',
        template = ''
    } = params

    if (type === 'Directory') { fs.mkdir(`${path}/${name}`, err => createItem(type, name, err, resolve)) }
    else { fs.writeFile(`${path}/${name}`, template, err => createItem('File', name, err, resolve)) }
}

function createItem(type, name, err, resolve) {
    if (err) throw err
    console.log(`${type} '${name}' created...`)
    resolve()
}
