**⚠️ Completionist is not finished, therefore the API is not stable, nor is it fully implemented.**

# Completionist API

To support the requirements of both a dynamically updated autocomplete, Completionist implements a JSON API over `std::cin`. ~~For simplicity, when dynamic updating of the phrases and weightings is not required, a plain text can also be used.~~ *coming soon*

``` json
// Quick Start

// Send a query for the prefix "hello, world.", fetching 4 autocomplete suggestions.
>> { "type": "query", "prefix": "fo", "count": 4 }
<< { "type": "response", "prefix": "fo", "results": ["foo", "fog", "foo bar", "forget"] }

// Increment the weighting of a suggestion, or add it if not yet present.
>> { "type": "increment", "phrase": "hello" }
<< { "type": "ok", "phrase": "hello" }

// Forcibly remove a phrase from the phrasedata.
>> { "type": "remove", "phrase": "hello" }
<< { "type": "ok", "phrase": "hello" }
```



## Query

To get autocomplete suggestions for a given prefix, send a query to complete.
