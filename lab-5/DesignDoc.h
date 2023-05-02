/* To-Do:
 * #1: Describe your algorithm in pseudo code for the following data operation in the Gallery class:
 *   - curateArtwork(Arkwork newItem, Artist artist); (artwork curation: curate a new peice of
 *     artwork for the gallery.  newItem.ID and artist.ID are set to -1 (not available) initially.
 *     As a result, you'll need to assign this newItem a unique ID.  Check if the artist is already
 *     on the artistist using their name and email.  If new, assign this artist a unique ID and add
 *     them to the artistList.  If not new, retrieve their ID from the artistList.  You will also
 *     need to update the artworkListCurated and the artworkListForSale.  Finally, you will need to
 *     update the curationRecords to include this new curation.)
 *
 * #2: Describe your algorithm in pseudo code for the following data operation in the Gallery class:
 *   - sellArtwork(int artworkID, Customer customer); (artwork sale: sell a for-sale artwork to a
 *     customer.  customer.ID is set to -1 initially.  So you will need to find out if this customer
 *     is new or not using their name and email address.  If new, assign this customer s unique ID
 *     and add them to the customerList.  If not, retrieve their ID from customerList.  You will
 *     also need to check if the specified artworkID is still for sale.  If yes, update the
 *     artworkListForSale by removing this artwork that was just sold, and update the salesRecords
 *     to include this new sale.)
 *
 * #3: Describe your algorithm in pseudo code for the following data operation in the Gallery class:
 *   - genArtworksReport(ReportType reportType); (summarize a gallery's curated artworks by their
 *     type, style, and subject.  ReportType is an enum class that consists of {artType, artStyle,
 *     artSubject}.  For example, if reportType is ReportType::artType, your summary will consit of
 *     the following pairs: (ArtType::painting, #), (ArtType::photography, #),
 *     (ArtType::drawing, #), (ArtType::sculpture, #), (ArtType::other, #).  Here, ArtType is
 *     another user-defined enum class.  Your algorithm is going to replace the # with the actual
 *     number of artworks of the corresponding artType.)
*/

/* Algorithms
 *
 * curateArtwork() | Time complexity: O(n)
 * (Start)
 *   If artist does not exist:
 *     Generate a new artist ID
 *     Add artist to artist list
 *   Add artist to artwork
 *   Add artwork to artworkListCurated and artworkListForSale
 *   Create new curation
 *   Add curation to curationRecords
 * (End)
 *
 * sellArtwork() | Time complexity: O(n)
 * (Start)
 *   If artwork is not for sale, return
 *   If customer does not exist:
 *     Generate a new customer ID
 *     Add customer to customer list
 *   Remove artwork from artworkListForSale
 *   Create new sale
 *   Add sale to salesRecords
 * (End)
 *     
 *
 *
 * genArtworksReport()
*/
