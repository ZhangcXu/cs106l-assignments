#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  auto vec = find_all(source.begin(), source.end(), ::isspace);

  Corpus tokens;
  std::transform(
    vec.begin(), 
    vec.end() - 1,  // first range: [begin, last-1]
    vec.begin() + 1, // second range: [begin+1, end]
    std::inserter(tokens, tokens.end()), // output
    [&source](auto it1, auto it2) {  // binary_op: create Token from consecutive pairs
      return Token(source, it1, it2);
    }
  );

  std::erase_if(tokens, [](const Token& t) {
    return t.content.empty();
  });

  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  auto misspelled_view = source
  | std::ranges::views::filter([&dictionary](const Token& t) {
    return !dictionary.contains(t.content);
  });

  auto suggestions_view = misspelled_view
  | std::ranges::views::transform([&dictionary](const Token& token) {
    auto suggestions = dictionary
    | std::ranges::views::filter([&token](const std::string& word) {
      return levenshtein(token.content, word) == 1;
    });
            
  
    std::set<std::string> suggestion_set(suggestions.begin(), suggestions.end());
      return Misspelling{token, suggestion_set};
  });

  auto valid_misspellings = suggestions_view
  | std::ranges::views::filter([](const Misspelling& m) {
    return !m.suggestions.empty();
  });
  
  return std::set<Misspelling>(valid_misspellings.begin(), valid_misspellings.end());
};

/* Helper methods */

#include "utils.cpp"