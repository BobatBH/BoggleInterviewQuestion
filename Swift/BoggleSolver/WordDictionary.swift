
import Foundation

let minWordLength = 3
let maxWordLength = 16

class WordDictionary {
    private let dictionaryFileName = "dictionary.json"

    let wordList: [String]

    init() throws {
        let data = try Data(contentsOf: URL(fileURLWithPath: dictionaryFileName), options: .mappedIfSafe)
        let json = try JSONSerialization.jsonObject(with: data, options: .mutableContainers)

        guard let jsonDictionary = json as? [String: [String]], let words = jsonDictionary["words"] else {
            throw WordDictionaryError.invalidContentFormat
        }

        wordList = words
        print("word dictionary created with \(wordList.count) entries")
    }

    enum WordDictionaryError: Error {
        case invalidContentFormat
    }
}
